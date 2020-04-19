/* UserProfile.re */
module Query = [%relay.query {|
  query UserProfileQuery($name: String!) {
    npm {
      package(name: $name) {
        downloads {
          lastMonth {
            count
          }
        }
      }
    }
  }
|}];

[@react.component]
let make = (~name) => {
  let queryData = Query.use(~variables={
    name: name
  }, ());
  switch(queryData.npm.package) {
    | Some(package) =>
      switch(package.downloads.lastMonth) {
        | Some(lastMonth) => <div>{React.string(string_of_int(lastMonth.count))}</div>
        | None => React.null
      }
    | None => React.null
  };
};
