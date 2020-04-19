/* @generated */

module Types = {
  type response_spotify_search_tracks = {
    id: option(string),
    name: option(string),
  };
  type response_spotify_search = {
    tracks: option(array(response_spotify_search_tracks)),
  };
  type response_spotify = {search: option(response_spotify_search)};

  type response = {spotify: response_spotify};
  type refetchVariables = {query: option(string)};
  let makeRefetchVariables = (~query=?, ()): refetchVariables => {
    query: query,
  };
  type variables = {query: option(string)};
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"spotify_search":{"n":""},"spotify_search_tracks":{"n":""},"spotify_search_tracks_id":{"n":""},"spotify_search_tracks_name":{"n":""}}} |json}
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
    {json| {"__root":{"query":{"n":""}}} |json}
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
  let makeVariables = (~query=?, ()): variables => {query: query};
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "query",
    "type": "String",
    "defaultValue": "you and i dash berlin"
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "spotify",
    "storageKey": null,
    "args": null,
    "concreteType": "SpotifyQuery",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "search",
        "storageKey": null,
        "args": [
          {
            "kind": "ObjectValue",
            "name": "data",
            "fields": [
              {
                "kind": "Variable",
                "name": "query",
                "variableName": "query"
              }
            ]
          }
        ],
        "concreteType": "SpotifySearchResults",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "tracks",
            "storageKey": null,
            "args": null,
            "concreteType": "SpotifyTrack",
            "plural": true,
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
                "name": "name",
                "args": null,
                "storageKey": null
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
    "name": "GitHubMilestone_SpotifySearchQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "GitHubMilestone_SpotifySearchQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "query",
    "name": "GitHubMilestone_SpotifySearchQuery",
    "id": null,
    "text": "query GitHubMilestone_SpotifySearchQuery(\n  $query: String = \"you and i dash berlin\"\n) {\n  spotify {\n    search(data: {query: $query}) {\n      tracks {\n        id\n        name\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |json}
];
