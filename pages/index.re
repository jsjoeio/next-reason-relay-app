%raw
"require('../styles/main.css')";

module P = {
  [@react.component]
  let make = (~children) => <p className="mb-2"> children </p>;
};

// ask Sean later about GitHubMilestone. looking in module

[@react.component]
let make = () =>
  <div>
    <React.Suspense
      fallback={<div> "One second, loading..."->React.string </div>}>
      <GitHubMilestone
        repo=GitHubMilestone.{name: "test-goal-tracker", owner: "jsjoeio"}
      />
      <UserProfile name="nextjs" />
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
    <h1 className="text-3xl font-semibold">
      "What :rock is this about?"->ReasonReact.string
    </h1>
    <P>
      {j| This is 😃iscool! worldThis is a simple template for a Next
      project using Reason & TailwindCSS.|j}
      ->React.string
    </P>
    <h2 className="text-2xl font-semibold mt-5">
      "Quick Start"->React.string
    </h2>
    <P>
      <pre>
        {j|git clone https://github.com/ryyppy/nextjs-default.git my-project
cd my-project
rm -rf .git|j}
        ->React.string
      </pre>
    </P>
  </div>;

let default = make;