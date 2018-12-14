type route =
  | Home;

type state = {route};

type action =
  | SetRoute(route);

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,

  initialState: () => {route: Home},

  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.hash) {
        | _ => self.send(SetRoute(Home))
        }
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },

  reducer: (action, _state) =>
    switch (action) {
    | SetRoute(r) => ReasonReact.Update({route: r})
    },

  render: _self =>
    <LayoutView> <p> {ReasonReact.string("Hello, world!")} </p> </LayoutView>,
};
