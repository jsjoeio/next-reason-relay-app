[@bs.val] external _context: Js.Nullable.t(string) = "process.env.CONTEXT";
[@bs.val] external _netlify: Js.Nullable.t(string) = "process.env.NETLIFY";

[@bs.val] external _nodeEnv: Js.Nullable.t(string) = "process.env.NODE_ENV";

type context =
  | DEV
  | PROD
  | PREVIEW
  | BRANCH
  | OTHER(string);

let contextOfString =
  fun
  | "production" => PROD
  | "deploy-preview" => PREVIEW
  | "branch-deploy" => BRANCH
  | other => OTHER(other);

let context =
  _context
  ->Js.Nullable.toOption
  ->Belt.Option.mapWithDefault(DEV, contextOfString);

let netlify =
  _netlify
  ->Js.Nullable.toOption
  ->Belt.Option.mapWithDefault(false, v => v == "true");

type nodeEnv =
  | Prod
  | Other;

let nodeEnv =
  _nodeEnv
  ->Js.Nullable.toOption
  ->Belt.Option.mapWithDefault(Other, v => v == "production" ? Prod : Other);

let isProd = nodeEnv == Prod;