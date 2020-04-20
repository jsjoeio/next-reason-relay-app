let isSsr: bool = [%bs.raw {|typeof window === "undefined"|}];

let appId = "cf1a5099-022b-4675-b24f-62fa07d9a9ec";

let oneGraphUrl = {j|https://serve.onegraph.com/graphql?app_id=$appId|j};

let authConfig =
  OneGraphAuth.createOptions(
    ~appId,
    ~oneGraphOrigin="https://serve.onegraph.com",
    (),
  );

let auth = isSsr ? None : Some(OneGraphAuth.create(authConfig));

let oneGraphSubscriptionClient =
  auth->Belt.Option.map(oneGraphAuth =>
    OneGraphSubscriptionClient.make(appId, {oneGraphAuth: oneGraphAuth})
  );

/* Subscriptions to OneGraph will work server-side, but just disable them in SSR for now. */
let subscriptionFunction: option(ReasonRelay.Network.subscribeFn) =
  oneGraphSubscriptionClient->Belt.Option.map(
    (
      oneGraphSubscriptionClient,
      operation: ReasonRelay.Network.operation,
      variables: Js.Json.t,
      _cacheConfig: ReasonRelay.cacheConfig,
    ) => {
    let subscribeObservable =
      oneGraphSubscriptionClient->OneGraphSubscriptionClient.request({
        "query": operation.text,
        "variables": variables,
        "operationName": operation.name,
      });

    let observable =
      ReasonRelay.Observable.make(sink => {
        subscribeObservable
        ->OneGraphSubscriptionClient.subscribe({
            "next": data => {
              sink.next(data);
            },
            "error": sink.error,
            "complete": sink.completed,
          })
        ->ignore
      });

    observable;
  });
