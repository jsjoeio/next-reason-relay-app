/* @generated */

module Types = {
  type response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository_issues = {
    totalCount: int,
  };
  type response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository = {
    issues: response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository_issues,
    name: string,
    id: string,
  };
  type response_npm_allPublishActivity_package_repository_sourceRepository = [
    | `GitHubRepository(
        response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository,
      )
    | `UnselectedUnionMember(string)
  ];
  type response_npm_allPublishActivity_package_repository = {
    sourceRepository:
      option(
        [
          | `GitHubRepository(
              response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository,
            )
          | `UnselectedUnionMember(string)
        ],
      ),
  };
  type response_npm_allPublishActivity_package_distTags_latest = {
    versionString: option(string),
  };
  type response_npm_allPublishActivity_package_distTags = {
    latest: option(response_npm_allPublishActivity_package_distTags_latest),
  };
  type response_npm_allPublishActivity_package = {
    id: option(string),
    keywords: option(array(string)),
    name: option(string),
    readme: option(string),
    homepage: option(string),
    distTags: option(response_npm_allPublishActivity_package_distTags),
    repository: option(response_npm_allPublishActivity_package_repository),
  };
  type response_npm_allPublishActivity = {
    package: response_npm_allPublishActivity_package,
  };
  type response_npm = {
    allPublishActivity: option(response_npm_allPublishActivity),
  };

  type response = {npm: response_npm};
  type variables = unit;
};

let unwrap_response_npm_allPublishActivity_package_repository_sourceRepository:
  {. "__typename": string} =>
  [
    | `GitHubRepository(
        Types.response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository,
      )
    | `UnselectedUnionMember(string)
  ] =
  u =>
    switch (u##__typename) {
    | "GitHubRepository" => `GitHubRepository(u->Obj.magic)
    | v => `UnselectedUnionMember(v)
    };

let wrap_response_npm_allPublishActivity_package_repository_sourceRepository:
  [
    | `GitHubRepository(
        Types.response_npm_allPublishActivity_package_repository_sourceRepository_GitHubRepository,
      )
    | `UnselectedUnionMember(string)
  ] =>
  {. "__typename": string} =
  fun
  | `GitHubRepository(v) => v->Obj.magic
  | `UnselectedUnionMember(v) => {"__typename": v};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"npm_allPublishActivity":{"n":""},"npm_allPublishActivity_package_id":{"n":""},"npm_allPublishActivity_package_keywords":{"n":""},"npm_allPublishActivity_package_name":{"n":""},"npm_allPublishActivity_package_readme":{"n":""},"npm_allPublishActivity_package_homepage":{"n":""},"npm_allPublishActivity_package_distTags":{"n":""},"npm_allPublishActivity_package_distTags_latest":{"n":""},"npm_allPublishActivity_package_distTags_latest_versionString":{"n":""},"npm_allPublishActivity_package_repository":{"n":""},"npm_allPublishActivity_package_repository_sourceRepository":{"n":"","u":"response_npm_allPublishActivity_package_repository_sourceRepository"}}} |json}
  ];
  let responseConverterMap = {
    "response_npm_allPublishActivity_package_repository_sourceRepository": unwrap_response_npm_allPublishActivity_package_repository_sourceRepository,
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

module Utils = {};

type operationType = ReasonRelay.subscriptionNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v1 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "name",
  "args": null,
  "storageKey": null
},
v2 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "npm",
    "storageKey": null,
    "args": null,
    "concreteType": "NpmSubscriptionRoot",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "allPublishActivity",
        "storageKey": null,
        "args": null,
        "concreteType": "NpmNewPackagePublishedSubscriptionPayload",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "package",
            "storageKey": null,
            "args": null,
            "concreteType": "NpmPackage",
            "plural": false,
            "selections": [
              (v0/*: any*/),
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "keywords",
                "args": null,
                "storageKey": null
              },
              (v1/*: any*/),
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "readme",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "homepage",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "distTags",
                "storageKey": null,
                "args": null,
                "concreteType": "NpmPackageDistTags",
                "plural": false,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "latest",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "NpmPackageMetadataDistTagLatestEntry",
                    "plural": false,
                    "selections": [
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "versionString",
                        "args": null,
                        "storageKey": null
                      }
                    ]
                  }
                ]
              },
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "repository",
                "storageKey": null,
                "args": null,
                "concreteType": "NpmPackageRepository",
                "plural": false,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "sourceRepository",
                    "storageKey": null,
                    "args": null,
                    "concreteType": null,
                    "plural": false,
                    "selections": [
                      {
                        "kind": "ScalarField",
                        "alias": null,
                        "name": "__typename",
                        "args": null,
                        "storageKey": null
                      },
                      {
                        "kind": "InlineFragment",
                        "type": "GitHubRepository",
                        "selections": [
                          (v0/*: any*/),
                          (v1/*: any*/),
                          {
                            "kind": "LinkedField",
                            "alias": null,
                            "name": "issues",
                            "storageKey": "issues(first:10,orderBy:{\"direction\":\"DESC\",\"field\":\"CREATED_AT\"},states:\"OPEN\")",
                            "args": [
                              {
                                "kind": "Literal",
                                "name": "first",
                                "value": 10
                              },
                              {
                                "kind": "Literal",
                                "name": "orderBy",
                                "value": {
                                  "direction": "DESC",
                                  "field": "CREATED_AT"
                                }
                              },
                              {
                                "kind": "Literal",
                                "name": "states",
                                "value": "OPEN"
                              }
                            ],
                            "concreteType": "GitHubIssueConnection",
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
      }
    ]
  }
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "NpmPackagesLive_PublishSubscription",
    "type": "Subscription",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": (v2/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "NpmPackagesLive_PublishSubscription",
    "argumentDefinitions": [],
    "selections": (v2/*: any*/)
  },
  "params": {
    "operationKind": "subscription",
    "name": "NpmPackagesLive_PublishSubscription",
    "id": null,
    "text": "subscription NpmPackagesLive_PublishSubscription {\n  npm {\n    allPublishActivity {\n      package {\n        id\n        keywords\n        name\n        readme\n        homepage\n        distTags {\n          latest {\n            versionString\n          }\n        }\n        repository {\n          sourceRepository {\n            __typename\n            ... on GitHubRepository {\n              id\n              name\n              issues(first: 10, orderBy: {direction: DESC, field: CREATED_AT}, states: OPEN) {\n                totalCount\n              }\n            }\n          }\n        }\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
