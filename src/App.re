type playlistLink =
  | You(string)
  | Them(list(string));

type state = {
  route: list(string),
  yourPlaylistLink: option(string),
  theirPlaylistLinks: option(list(string)),
};

type action =
  | SetRoute(list(string))
  | SetLink(playlistLink);

let component = ReasonReact.reducerComponent("App");
let make = _children => {
  ...component,

  initialState: () => {
    let url = ReasonReact.Router.dangerouslyGetInitialUrl();
    {route: url.path, yourPlaylistLink: None, theirPlaylistLinks: None};
  },

  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url => self.send(SetRoute(url.path)));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },

  reducer: (action, state) =>
    switch (action) {
    | SetRoute(r) => ReasonReact.Update({...state, route: r})
    | SetLink(You(link)) =>
      ReasonReact.Update({...state, yourPlaylistLink: Some(link)})
    | SetLink(Them(links)) =>
      ReasonReact.Update({...state, theirPlaylistLinks: Some(links)})
    },

  render: self =>
    <LayoutView>
      {switch (self.state.route) {
       | ["you"] =>
         <YouView onChangeLink={uri => self.send(SetLink(You(uri)))} />
       | ["them"] => <ThemView />
       | _ => <HomeView />
       }}
    </LayoutView>,
};
