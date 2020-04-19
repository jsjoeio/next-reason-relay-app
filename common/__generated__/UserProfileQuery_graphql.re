/* @generated */

module Types = {
  type response_npm_package_downloads_lastMonth = {count: int};
  type response_npm_package_downloads = {
    lastMonth: option(response_npm_package_downloads_lastMonth),
  };
  type response_npm_package = {downloads: response_npm_package_downloads};
  type response_npm = {package: option(response_npm_package)};

  type response = {npm: response_npm};
  type refetchVariables = {name: option(string)};
  let makeRefetchVariables = (~name=?, ()): refetchVariables => {name: name};
  type variables = {name: string};
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"npm_package":{"n":""},"npm_package_downloads_lastMonth":{"n":""}}} |json}
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
  let makeVariables = (~name): variables => {name: name};
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "name",
    "type": "String!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "npm",
    "storageKey": null,
    "args": null,
    "concreteType": "NpmQuery",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "package",
        "storageKey": null,
        "args": [
          {
            "kind": "Variable",
            "name": "name",
            "variableName": "name"
          }
        ],
        "concreteType": "NpmPackage",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "downloads",
            "storageKey": null,
            "args": null,
            "concreteType": "NpmPackageDownloadData",
            "plural": false,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "lastMonth",
                "storageKey": null,
                "args": null,
                "concreteType": "NpmPackageDownloadPeriodData",
                "plural": false,
                "selections": [
                  {
                    "kind": "ScalarField",
                    "alias": null,
                    "name": "count",
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
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "UserProfileQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "UserProfileQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "query",
    "name": "UserProfileQuery",
    "id": null,
    "text": "query UserProfileQuery(\n  $name: String!\n) {\n  npm {\n    package(name: $name) {\n      downloads {\n        lastMonth {\n          count\n        }\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
