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
  | {gitHub: Some({repository: Some({projects})})} =>
    Js.log(projects);
    let thing = "test";
    <div> {React.string("It worked")} </div>;
  | _ => React.null
  };
  // switch (queryData) {
  // | {gitHub: Some({repository: Some({milestones})})} =>
  //   let milestones =
  //     GitHubMilestoneQuery_graphql.Utils.getConnectionNodes_milestones(
  //       milestones,
  //     );
  //   let milestoneCount = milestones->Belt.Array.length->string_of_int;
  //   <div>
  //     {j|Found Milestones: $milestoneCount|j}->React.string
  //     {milestones
  //      ->Belt.Array.map(milestone =>
  //          <div>
  //            <Milestone gitHubMilestone={milestone.getFragmentRefs()} />
  //          </div>
  //        )
  //      ->React.array}
  //   </div>;
  // | _ => React.null
  // };
};