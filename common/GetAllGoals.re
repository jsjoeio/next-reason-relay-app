module Query = [%relay.query
  {|
query GetAllGoalsQuery($repoName: String!, $repoOwner: String!) {
  gitHub {
    repository(name: $repoName, owner: $repoOwner) {
      projects(first: 5, orderBy: { direction: DESC, field: CREATED_AT }) {
        edges {
          node {
            createdAt
            body
            bodyHTML
            closed
            closedAt
            id
            name
            number
            state
            updatedAt
            columns(first: 10) {
              edges {
                node {
                  cards(first: 10, archivedStates: NOT_ARCHIVED) {
                    totalCount
                  }
                  id
                  name
                }
              }
            }
          }
        }
      }
    }
  }
}
|}
];

// this is one unit
type repo = {
  owner: string,
  name: string,
};

let default = {owner: "onegraph", name: "onegraph-auth"};

[@react.component]
let make = (~repo=default) => {
  // more generally useful
  // let repo = Belt.Option.getWithDefault(repo, default)
  let name = repo.name;
  let owner = repo.owner;

  let queryData =
    Query.use(~variables={repoOwner: owner, repoName: name}, ());
  ();

  switch (queryData) {
  | {gitHub: Some({repository: Some({projects: {edges: Some(nodes)}})})} =>
    let projects =
      nodes->Belt.Array.map(node => {
        switch (node) {
        | Some({node: Some({name, createdAt, id, body})}) =>
          <div key=id>
            <h3> {React.string(name)} </h3>
            {switch (body) {
             | Some(body) => <p> {React.string(body)} </p>
             | _ => React.null
             }}
            <p> {j|Created at: $createdAt|j}->React.string </p>
          </div>
        | _ => React.null
        }
      });

    <div> {React.array(projects)} </div>;
  | _ => React.null
  };
};