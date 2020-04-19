/* @generated */

type enum_GitHubMilestoneState = [
  | `CLOSED
  | `OPEN
  | `FutureAddedValue(string)
];

let unwrap_enum_GitHubMilestoneState: string => enum_GitHubMilestoneState =
  fun
  | "CLOSED" => `CLOSED
  | "OPEN" => `OPEN
  | v => `FutureAddedValue(v);

let wrap_enum_GitHubMilestoneState: enum_GitHubMilestoneState => string =
  fun
  | `CLOSED => "CLOSED"
  | `OPEN => "OPEN"
  | `FutureAddedValue(v) => v;

module Types = {
  type fragment = {
    id: string,
    description: option(string),
    title: string,
    createdAt: string,
    number: int,
    state: [ | `CLOSED | `OPEN | `FutureAddedValue(string)],
  };
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"description":{"n":""},"state":{"e":"enum_GitHubMilestoneState"}}} |json}
  ];
  let fragmentConverterMap = {
    "enum_GitHubMilestoneState": unwrap_enum_GitHubMilestoneState,
  };
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__Milestone_gitHubMilestone": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "kind": "Fragment",
  "name": "Milestone_gitHubMilestone",
  "type": "GitHubMilestone",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "id",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "description",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "title",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "createdAt",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "number",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "state",
      "args": null,
      "storageKey": null
    }
  ]
} |json}
];
