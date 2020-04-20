%raw
"require('../styles/main.css')";

module P = {
  [@react.component]
  let make = (~children) => <p className="mb-2"> children </p>;
};

// ask Sean later about GitHubMilestone. looking in module

[@react.component]
let make = () => {
  let (packageName, setPackageName) = React.useState(() => "nextjs");
  let (repo, setRepo) =
    React.useState(() => GitHubMilestone.{name: "blog", owner: "sgrove"});

  <div>
    <React.Suspense
      fallback={<div> "One second, loading milestones..."->React.string </div>}>
      <h1 className="text-3xl font-semibold">
        "GitHubMilestones: "->React.string
      </h1>
      <GitHubMilestone repo />
    </React.Suspense>
    <br />
    <h1 className="text-3xl font-semibold">
      {j|npm downloads for|j}->React.string
      <input
        type_="text"
        defaultValue=packageName
        onKeyDown={event => {
          let key = ReactEvent.Keyboard.key(event);
          switch (key) {
          | "Enter" =>
            ReactEvent.Keyboard.preventDefault(event);
            ReactEvent.Keyboard.stopPropagation(event);
            let newPackageName = ReactEvent.Keyboard.target(event)##value;
            setPackageName(_ => newPackageName);
          | _ => ()
          };
        }}
      />
      {j|package:|j}->React.string
    </h1>
    <React.Suspense
      fallback={
        <div>
          {j|One second, loading npm download stats for $packageName...|j}
          ->React.string
        </div>
      }>
      <UserProfile name=packageName />
    </React.Suspense>
    <br />
    <React.Suspense
      fallback={<div> "One second, loading milestones..."->React.string </div>}>
      <h1 className="text-3xl font-semibold">
        "Live npm subscription with optional GitHub data: "->React.string
      </h1>
      <br />
      <NpmPackagesLive />
    </React.Suspense>
    <hr />
    <button
      onClick={_ =>
        Config.auth->Belt.Option.map(auth => {
          OneGraphAuth.login(auth, "github")
          |> Js.Promise.then_(() => {
               OneGraphAuth.isLoggedIn(auth, "github")
               |> Js.Promise.then_(isLoggedIn => {
                    Js.log2("Success? ", isLoggedIn);
                    (
                      switch (isLoggedIn) {
                      | false => Js.log("logged in failed")
                      | true => Js.log("Logged in success")
                      }
                    )
                    |> Js.Promise.resolve;
                  })
             })
        })
        |> ignore
      }>
      {React.string("Login")}
    </button>
  </div>;
};

let default = make;
