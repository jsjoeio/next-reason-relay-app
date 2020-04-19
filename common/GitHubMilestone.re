module Query = [%relay.query
  {|
query GitHubMilestoneQuery(
  $name: String = "test-goal-tracker"
  $owner: String = "jsjoeio"
) {
  gitHub {
    repository(name: $name, owner: $owner) {
      milestones(first: 10, orderBy: { direction: DESC, field: CREATED_AT })
        @connection(key: "GitHubMilestone_milestones") {
        edges {
          node {
            ...Milestone_gitHubMilestone
          }
        }
      }
    }
  }
}

|}
];

module SpotifySearchQuery = [%relay.query
  {|
  query GitHubMilestone_SpotifySearchQuery(
    $query: String = "you and i dash berlin"
  ) {
    spotify {
      search(data: { query: $query }) {
        tracks {
          id
          name
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
    Query.use(~variables={owner: Some(owner), name: Some(name)}, ());

  switch (queryData) {
  | {gitHub: Some({repository: Some({milestones})})} =>
    let milestones =
      GitHubMilestoneQuery_graphql.Utils.getConnectionNodes_milestones(
        milestones,
      );

    let milestoneCount = milestones->Belt.Array.length->string_of_int;
    <div>
      {j|Found Milestones: $milestoneCount|j}->React.string
      {milestones
       ->Belt.Array.map(milestone =>
           <Milestone gitHubMilestone={milestone.getFragmentRefs()} />
         )
       ->React.array}
    </div>;
  | _ => React.null
  };
};