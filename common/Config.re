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

let host =
  Env.isProd ? "https://serve.onegraph.com" : "https://serve.onegraph.com";

// let authConfig = OneGraphAuth.createOptions(~appId, ~oneGraphOrigin, ());

// let auth = isSsr ? None : Some(OneGraphAuth.create(authConfig));

// let host = Env.isProd ? "serve.apilaw.com" : "10.0.1.16:8080";

let httpUri = oneGraphUrl;


// let webSocketUri =
//   Env.isProd ? {j|wss://$host/v1/graphql|j} : {j|ws://$host/v1/graphql|j};

// module WSSubscriptClient = {
//   type subClient;
//   type newSubscriptionClientOptions = {reconnect: bool};
//   [@bs.module "subscriptions-transport-ws"] [@bs.new]
//   external make: (string, newSubscriptionClientOptions) => subClient =
//     "SubscriptionClient";

//   type observable;
//   [@bs.send]
//   external request: (subClient, Js.t('a)) => observable = "request";
//   [@bs.send] external subscribe: (observable, Js.t('a)) => unit = "subscribe";
// };

// let subscriptionClient =
//   WSSubscriptClient.make(webSocketUri, {reconnect: true});

// let subscriptionFunction: ReasonRelay.Network.subscribeFn =
//   (operation, variables: Js.Json.t, _cacheConfig: ReasonRelay.cacheConfig) => {
//     let subscribeObservable =
//       subscriptionClient->WSSubscriptClient.request({
//         "query": operation.text,
//         "variables": variables,
//         "operationName": operation.name,
//       });

//     let observable =
//       ReasonRelay.Observable.make(sink => {
//         subscribeObservable
//         ->WSSubscriptClient.subscribe({
//             "next": data => {
//               sink.next(data);
//             },
//             "error": sink.error,
//             "complete": sink.completed,
//           })
//         ->ignore
//       });

//     observable;
//   };