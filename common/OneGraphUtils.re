let loginToGitHub = (~auth, ~onIsLoggedIn, ~onIsNotLoggedIn=?, ()) => {
  OneGraphAuth.login(auth, "github")
  |> Js.Promise.then_(() => {
       OneGraphAuth.isLoggedIn(auth, "github")
       |> Js.Promise.then_(isLoggedIn => {
            (
              switch (isLoggedIn) {
              | false =>
                onIsNotLoggedIn->Belt.Option.forEach(onIsNotLoggedIn =>
                  onIsNotLoggedIn()
                )
              | true => onIsLoggedIn()
              }
            )
            |> Js.Promise.resolve
          })
     });
};

let logoutOfGitHub = (~auth, ~onIsLoggedIn=?, ~onIsNotLoggedIn, ()) => {
  OneGraphAuth.logout(auth, "github", ())
  |> Js.Promise.then_(_ => {
       OneGraphAuth.isLoggedIn(auth, "github")
       |> Js.Promise.then_(isLoggedIn => {
            (
              switch (isLoggedIn) {
              | false => onIsNotLoggedIn()
              | true =>
                onIsLoggedIn->Belt.Option.forEach(onIsLoggedIn =>
                  onIsLoggedIn()
                )
              }
            )
            |> Js.Promise.resolve
          })
     });
};

/**
    Note that these will look a lot better once we have extensible lets (see
    https://github.com/aantron/promise/issues/52). Here's a sketch of what it
    might look like with both a promise async/await-let and an Option-let:

let logoutOfGitHub_withMonadicLetFeature_like_async_await =
    (~auth, ~onIsLoggedIn=?, ~onIsNotLoggedIn, ()) => {
  let*await _ = OneGraphAuth.logout(auth, "github", ());
  let*await isLoggedIn = OneGraphAuth.isLoggedIn(auth, "github");

  switch (isLoggedIn) {
  | false => onIsNotLoggedIn()
  | true =>
    /* Use the Option-let to pull out Some(handler) or immediately return None */
    let*option stillLoggedInHandler = onIsLoggedIn;
    stillLoggedInHandler();
  };
};*/;
