type route =
  | Home;

type state = {route};

type action =
  | ShowHome;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,

  initialState: () => {route: Home},

  reducer: (action, _state) =>
    switch (action) {
    | ShowHome => ReasonReact.Update({route: Home})
    },

  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        switch (url.hash) {
        | _ => self.send(ShowHome)
        }
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },

  render: _self => <p> {ReasonReact.string("Hello, world!")} </p>,
};
