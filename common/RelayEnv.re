[%bs.raw {|require('isomorphic-fetch')|}];
[@bs.send] external authHeaders_: 't => Js.Dict.t(string) = "authHeaders";
/* RelayEnv.re */
/* This is just a custom exception to indicate that something went wrong. */
exception GraphqlError(string);

let authHeaders = auth => {
  let headers = authHeaders_(auth);
  Js.Dict.get(headers, "Authorization");
};
/**
 * A standard fetch that sends our operation and variables to the
 * GraphQL server, and then decodes and returns the response.
 */
let fetchQuery: ReasonRelay.Network.fetchFunctionPromise =
  (operation, variables, _cacheConfig) => {
    let authHeader =
      Config.auth->Belt.Option.flatMap(auth => authHeaders(auth));

    Fetch.(
      fetchWithInit(
        Config.oneGraphUrl,
        RequestInit.make(
          ~method_=Post,
          ~body=
            Js.Dict.fromList([
              ("query", Js.Json.string(operation.text)),
              ("variables", variables),
            ])
            |> Js.Json.object_
            |> Js.Json.stringify
            |> BodyInit.make,
          ~headers=
            HeadersInit.make({
              "content-type": "application/json",
              "accept": "application/json",
              "Authorization": authHeader->Belt.Option.getWithDefault(""),
            }),
          (),
        ),
      )
      |> Js.Promise.then_(resp =>
           if (Response.ok(resp)) {
             Response.json(resp);
           } else {
             Js.Promise.reject(
               GraphqlError("Request failed: " ++ Response.statusText(resp)),
             );
           }
         )
    );
  };

let network =
  ReasonRelay.Network.makePromiseBased(
    ~fetchFunction=fetchQuery,
    ~subscriptionFunction=?Config.subscriptionFunction,
    (),
  );

let environment =
  ReasonRelay.Environment.make(
    ~network,
    ~store=
      ReasonRelay.Store.make(
        ~source=ReasonRelay.RecordSource.make(),
        ~gcReleaseBufferSize=100,
        (),
      ),
    (),
  );
