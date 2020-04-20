type t;

type subscriptionClientOptions = {oneGraphAuth: OneGraphAuth.t};

[@bs.module "onegraph-subscription-client"] [@bs.new "SubscriptionClient"]
external make: (string, subscriptionClientOptions) => t = "SubscriptionClient";

type observable;
[@bs.send] external request: (t, Js.t('a)) => observable = "request";
[@bs.send] external subscribe: (observable, Js.t('a)) => unit = "subscribe";
