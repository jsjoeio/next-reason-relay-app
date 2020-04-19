module GitHubMilestoneFragment = [%relay.fragment
  {|
  fragment Milestone_gitHubMilestone on GitHubMilestone {
    id
    description
    title
    createdAt
    number
    state
  }
|}
];

[@react.component]
let make = (~gitHubMilestone) => {
  let gitHubMilestone = GitHubMilestoneFragment.use(gitHubMilestone);

  React.string(gitHubMilestone.title);
};