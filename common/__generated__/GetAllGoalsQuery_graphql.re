/* @generated */

type enum_GitHubProjectState = [
  | `CLOSED
  | `OPEN
  | `FutureAddedValue(string)
];

let unwrap_enum_GitHubProjectState: string => enum_GitHubProjectState =
  fun
  | "CLOSED" => `CLOSED
  | "OPEN" => `OPEN
  | v => `FutureAddedValue(v);

let wrap_enum_GitHubProjectState: enum_GitHubProjectState => string =
  fun
  | `CLOSED => "CLOSED"
  | `OPEN => "OPEN"
  | `FutureAddedValue(v) => v;

module Types = {
  type response_gitHub_repository_projects_edges_node_columns_edges_node_cards = {
    totalCount: int,
  };
  type response_gitHub_repository_projects_edges_node_columns_edges_node = {
    cards: response_gitHub_repository_projects_edges_node_columns_edges_node_cards,
    id: string,
    name: string,
  };
  type response_gitHub_repository_projects_edges_node_columns_edges = {
    node:
      option(
        response_gitHub_repository_projects_edges_node_columns_edges_node,
      ),
  };
  type response_gitHub_repository_projects_edges_node_columns = {
    edges:
      option(
        array(
          option(
            response_gitHub_repository_projects_edges_node_columns_edges,
          ),
        ),
      ),
  };
  type response_gitHub_repository_projects_edges_node = {
    createdAt: string,
    body: option(string),
    bodyHTML: string,
    closed: bool,
    closedAt: option(string),
    id: string,
    name: string,
    number: int,
    state: [ | `CLOSED | `OPEN | `FutureAddedValue(string)],
    updatedAt: string,
    columns: response_gitHub_repository_projects_edges_node_columns,
  };
  type response_gitHub_repository_projects_edges = {
    node: option(response_gitHub_repository_projects_edges_node),
  };
  type response_gitHub_repository_projects = {
    edges: option(array(option(response_gitHub_repository_projects_edges))),
  };
  type response_gitHub_repository = {
    projects: response_gitHub_repository_projects,
  };
  type response_gitHub = {repository: option(response_gitHub_repository)};

  type response = {gitHub: option(response_gitHub)};
  type refetchVariables = {
    repoName: option(string),
    repoOwner: option(string),
  };
  let makeRefetchVariables = (~repoName=?, ~repoOwner=?, ()): refetchVariables => {
    repoName,
    repoOwner,
  };
  type variables = {
    repoName: string,
    repoOwner: string,
  };
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"gitHub":{"n":""},"gitHub_repository":{"n":""},"gitHub_repository_projects_edges":{"n":"","na":""},"gitHub_repository_projects_edges_node":{"n":""},"gitHub_repository_projects_edges_node_body":{"n":""},"gitHub_repository_projects_edges_node_closedAt":{"n":""},"gitHub_repository_projects_edges_node_state":{"e":"enum_GitHubProjectState"},"gitHub_repository_projects_edges_node_columns_edges":{"n":"","na":""},"gitHub_repository_projects_edges_node_columns_edges_node":{"n":""}}} |json}
  ];
  let responseConverterMap = {
    "enum_GitHubProjectState": unwrap_enum_GitHubProjectState,
  };
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type preloadToken;

module Utils = {
  open Types;
  let makeVariables = (~repoName, ~repoOwner): variables => {
    repoName,
    repoOwner,
  };
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "repoName",
    "type": "String!",
    "defaultValue": null
  },
  {
    "kind": "LocalArgument",
    "name": "repoOwner",
    "type": "String!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "name",
    "variableName": "repoName"
  },
  {
    "kind": "Variable",
    "name": "owner",
    "variableName": "repoOwner"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "name",
  "args": null,
  "storageKey": null
},
v4 = {
  "kind": "Literal",
  "name": "first",
  "value": 10
},
v5 = {
  "kind": "LinkedField",
  "alias": null,
  "name": "projects",
  "storageKey": "projects(first:5,orderBy:{\"direction\":\"DESC\",\"field\":\"CREATED_AT\"})",
  "args": [
    {
      "kind": "Literal",
      "name": "first",
      "value": 5
    },
    {
      "kind": "Literal",
      "name": "orderBy",
      "value": {
        "direction": "DESC",
        "field": "CREATED_AT"
      }
    }
  ],
  "concreteType": "GitHubProjectConnection",
  "plural": false,
  "selections": [
    {
      "kind": "LinkedField",
      "alias": null,
      "name": "edges",
      "storageKey": null,
      "args": null,
      "concreteType": "GitHubProjectEdge",
      "plural": true,
      "selections": [
        {
          "kind": "LinkedField",
          "alias": null,
          "name": "node",
          "storageKey": null,
          "args": null,
          "concreteType": "GitHubProject",
          "plural": false,
          "selections": [
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
              "name": "body",
              "args": null,
              "storageKey": null
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "bodyHTML",
              "args": null,
              "storageKey": null
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "closed",
              "args": null,
              "storageKey": null
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "closedAt",
              "args": null,
              "storageKey": null
            },
            (v2/*: any*/),
            (v3/*: any*/),
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
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "updatedAt",
              "args": null,
              "storageKey": null
            },
            {
              "kind": "LinkedField",
              "alias": null,
              "name": "columns",
              "storageKey": "columns(first:10)",
              "args": [
                (v4/*: any*/)
              ],
              "concreteType": "GitHubProjectColumnConnection",
              "plural": false,
              "selections": [
                {
                  "kind": "LinkedField",
                  "alias": null,
                  "name": "edges",
                  "storageKey": null,
                  "args": null,
                  "concreteType": "GitHubProjectColumnEdge",
                  "plural": true,
                  "selections": [
                    {
                      "kind": "LinkedField",
                      "alias": null,
                      "name": "node",
                      "storageKey": null,
                      "args": null,
                      "concreteType": "GitHubProjectColumn",
                      "plural": false,
                      "selections": [
                        {
                          "kind": "LinkedField",
                          "alias": null,
                          "name": "cards",
                          "storageKey": "cards(archivedStates:\"NOT_ARCHIVED\",first:10)",
                          "args": [
                            {
                              "kind": "Literal",
                              "name": "archivedStates",
                              "value": "NOT_ARCHIVED"
                            },
                            (v4/*: any*/)
                          ],
                          "concreteType": "GitHubProjectCardConnection",
                          "plural": false,
                          "selections": [
                            {
                              "kind": "ScalarField",
                              "alias": null,
                              "name": "totalCount",
                              "args": null,
                              "storageKey": null
                            }
                          ]
                        },
                        (v2/*: any*/),
                        (v3/*: any*/)
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        }
      ]
    }
  ]
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "GetAllGoalsQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "gitHub",
        "storageKey": null,
        "args": null,
        "concreteType": "GitHubQuery",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "repository",
            "storageKey": null,
            "args": (v1/*: any*/),
            "concreteType": "GitHubRepository",
            "plural": false,
            "selections": [
              (v5/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "GetAllGoalsQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "gitHub",
        "storageKey": null,
        "args": null,
        "concreteType": "GitHubQuery",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "repository",
            "storageKey": null,
            "args": (v1/*: any*/),
            "concreteType": "GitHubRepository",
            "plural": false,
            "selections": [
              (v5/*: any*/),
              (v2/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "GetAllGoalsQuery",
    "id": null,
    "text": "query GetAllGoalsQuery(\n  $repoName: String!\n  $repoOwner: String!\n) {\n  gitHub {\n    repository(name: $repoName, owner: $repoOwner) {\n      projects(first: 5, orderBy: {direction: DESC, field: CREATED_AT}) {\n        edges {\n          node {\n            createdAt\n            body\n            bodyHTML\n            closed\n            closedAt\n            id\n            name\n            number\n            state\n            updatedAt\n            columns(first: 10) {\n              edges {\n                node {\n                  cards(first: 10, archivedStates: NOT_ARCHIVED) {\n                    totalCount\n                  }\n                  id\n                  name\n                }\n              }\n            }\n          }\n        }\n      }\n      id\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
