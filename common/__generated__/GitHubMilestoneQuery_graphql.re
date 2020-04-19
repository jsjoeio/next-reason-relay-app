/* @generated */

module Types = {
  type response_gitHub_repository_milestones_edges_node = {
    getFragmentRefs:
      unit =>
      {
        .
        "__$fragment_ref__Milestone_gitHubMilestone": Milestone_gitHubMilestone_graphql.t,
      },
  };
  type response_gitHub_repository_milestones_edges = {
    node: option(response_gitHub_repository_milestones_edges_node),
  };
  type response_gitHub_repository_milestones = {
    edges:
      option(array(option(response_gitHub_repository_milestones_edges))),
  };
  type response_gitHub_repository = {
    milestones: option(response_gitHub_repository_milestones),
  };
  type response_gitHub = {repository: option(response_gitHub_repository)};

  type response = {gitHub: option(response_gitHub)};
  type refetchVariables = {
    name: option(string),
    owner: option(string),
  };
  let makeRefetchVariables = (~name=?, ~owner=?, ()): refetchVariables => {
    name,
    owner,
  };
  type variables = {
    name: option(string),
    owner: option(string),
  };
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"gitHub":{"n":""},"gitHub_repository":{"n":""},"gitHub_repository_milestones":{"n":""},"gitHub_repository_milestones_edges":{"n":"","na":""},"gitHub_repository_milestones_edges_node":{"n":"","f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"name":{"n":""},"owner":{"n":""}}} |json}
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
  let getConnectionNodes_milestones:
    option(response_gitHub_repository_milestones) =>
    array(response_gitHub_repository_milestones_edges_node) =
    connection =>
      switch (connection) {
      | None => [||]
      | Some(connection) =>
        switch (connection.edges) {
        | None => [||]
        | Some(edges) =>
          edges
          ->Belt.Array.keepMap(edge =>
              switch (edge) {
              | None => None
              | Some(edge) =>
                switch (edge.node) {
                | None => None
                | Some(node) => Some(node)
                }
              }
            )
        }
      };

  let makeVariables = (~name=?, ~owner=?, ()): variables => {name, owner};
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "name",
    "type": "String",
    "defaultValue": "test-goal-tracker"
  },
  {
    "kind": "LocalArgument",
    "name": "owner",
    "type": "String",
    "defaultValue": "jsjoeio"
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "name",
    "variableName": "name"
  },
  {
    "kind": "Variable",
    "name": "owner",
    "variableName": "owner"
  }
],
v2 = {
  "kind": "Literal",
  "name": "orderBy",
  "value": {
    "direction": "DESC",
    "field": "CREATED_AT"
  }
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "__typename",
  "args": null,
  "storageKey": null
},
v4 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "cursor",
  "args": null,
  "storageKey": null
},
v5 = {
  "kind": "LinkedField",
  "alias": null,
  "name": "pageInfo",
  "storageKey": null,
  "args": null,
  "concreteType": "GitHubPageInfo",
  "plural": false,
  "selections": [
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "endCursor",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "hasNextPage",
      "args": null,
      "storageKey": null
    }
  ]
},
v6 = [
  {
    "kind": "Literal",
    "name": "first",
    "value": 10
  },
  (v2/*: any*/)
],
v7 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "GitHubMilestoneQuery",
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
              {
                "kind": "LinkedField",
                "alias": "milestones",
                "name": "__GitHubMilestone_milestones_connection",
                "storageKey": "__GitHubMilestone_milestones_connection(orderBy:{\"direction\":\"DESC\",\"field\":\"CREATED_AT\"})",
                "args": [
                  (v2/*: any*/)
                ],
                "concreteType": "GitHubMilestoneConnection",
                "plural": false,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "edges",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "GitHubMilestoneEdge",
                    "plural": true,
                    "selections": [
                      {
                        "kind": "LinkedField",
                        "alias": null,
                        "name": "node",
                        "storageKey": null,
                        "args": null,
                        "concreteType": "GitHubMilestone",
                        "plural": false,
                        "selections": [
                          (v3/*: any*/),
                          {
                            "kind": "FragmentSpread",
                            "name": "Milestone_gitHubMilestone",
                            "args": null
                          }
                        ]
                      },
                      (v4/*: any*/)
                    ]
                  },
                  (v5/*: any*/)
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "GitHubMilestoneQuery",
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
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "milestones",
                "storageKey": "milestones(first:10,orderBy:{\"direction\":\"DESC\",\"field\":\"CREATED_AT\"})",
                "args": (v6/*: any*/),
                "concreteType": "GitHubMilestoneConnection",
                "plural": false,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "edges",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "GitHubMilestoneEdge",
                    "plural": true,
                    "selections": [
                      {
                        "kind": "LinkedField",
                        "alias": null,
                        "name": "node",
                        "storageKey": null,
                        "args": null,
                        "concreteType": "GitHubMilestone",
                        "plural": false,
                        "selections": [
                          (v7/*: any*/),
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
                          },
                          (v3/*: any*/)
                        ]
                      },
                      (v4/*: any*/)
                    ]
                  },
                  (v5/*: any*/)
                ]
              },
              {
                "kind": "LinkedHandle",
                "alias": null,
                "name": "milestones",
                "args": (v6/*: any*/),
                "handle": "connection",
                "key": "GitHubMilestone_milestones",
                "filters": [
                  "orderBy"
                ]
              },
              (v7/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "GitHubMilestoneQuery",
    "id": null,
    "text": "query GitHubMilestoneQuery(\n  $name: String = \"test-goal-tracker\"\n  $owner: String = \"jsjoeio\"\n) {\n  gitHub {\n    repository(name: $name, owner: $owner) {\n      milestones(first: 10, orderBy: {direction: DESC, field: CREATED_AT}) {\n        edges {\n          node {\n            ...Milestone_gitHubMilestone\n            id\n            __typename\n          }\n          cursor\n        }\n        pageInfo {\n          endCursor\n          hasNextPage\n        }\n      }\n      id\n    }\n  }\n}\n\nfragment Milestone_gitHubMilestone on GitHubMilestone {\n  id\n  description\n  title\n  createdAt\n  number\n  state\n}\n",
    "metadata": {
      "connection": [
        {
          "count": null,
          "cursor": null,
          "direction": "forward",
          "path": [
            "gitHub",
            "repository",
            "milestones"
          ]
        }
      ]
    }
  }
};
})() |json}
];
