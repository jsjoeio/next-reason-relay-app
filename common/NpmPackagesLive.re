module Subscription = [%relay.subscription
  {|
subscription NpmPackagesLive_PublishSubscription {
  npm {
    allPublishActivity {
      package {
        id
        keywords
        name
        readme
        homepage
        distTags {
          latest {
            versionString
          }
        }
        repository {
          sourceRepository {
          __typename
          ... on GitHubRepository {
              id
              name
              issues(
                first: 10
                orderBy: {
                  direction: DESC
                  field: CREATED_AT
                }
                states: OPEN
              ) {
                totalCount
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

type publishedPackage = {
  name: string,
  version: string,
  homepage: string,
  openIssueCount: option(int),
};

[@react.component]
let make = () => {
  let relayEnv = ReasonRelay.useEnvironmentFromContext();

  let (
    mostRecentlyPublishedPackage: option(publishedPackage),
    setMostRecentlyPublishedPackage,
  ) =
    React.useState(() => None);

  React.useEffect0(() => {
    let disposable: ReasonRelay.Disposable.t =
      Subscription.subscribe(
        ~environment=relayEnv,
        ~variables=(),
        ~onNext=
          response => {
            switch (response) {
            | {
                npm: {
                  allPublishActivity:
                    Some({
                      package: {
                        name: Some(name),
                        homepage: Some(homepage),
                        repository,
                        distTags:
                          Some({
                            latest: Some({versionString: Some(version)}),
                          }),
                      },
                    }),
                },
              } =>
              let openIssueCount =
                switch (repository) {
                | Some({
                    sourceRepository:
                      Some(`GitHubRepository({issues: {totalCount}})),
                  }) =>
                  Some(totalCount)
                | _ => None
                };

              setMostRecentlyPublishedPackage(_ =>
                Some({name, version, homepage, openIssueCount})
              );
            | _ => ()
            }
          },
        (),
      );

    /* Clean up/dispose of the subscription if we're unmounted */
    Some(() => disposable |> ReasonRelay.Disposable.dispose);
  });

  React.(
    switch (mostRecentlyPublishedPackage) {
    | None => "Waiting for a package to be published on npm..."->string
    | Some({name, version, homepage, openIssueCount}) =>
      let issueString =
        switch (openIssueCount) {
        | None => ""
        | Some(count) => {j| It currently has $count open issues on GitHub. |j}
        };

      <div>
        <strong> name->string </strong>
        {j|just published $version. $issueString|j}->string
        {j|You can find more at its |j}->string
        <a className="px-3 font-bold" target="_blank" href=homepage>
          {j|homepage⤴|j}->string
        </a>
      </div>;
    }
  );
};
