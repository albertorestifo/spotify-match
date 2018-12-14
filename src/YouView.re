type state = {uri: string};
type action =
  | Change(string);

let component = ReasonReact.reducerComponent("YouView");
let make = (~onChangeLink, _children) => {
  let handleSubmit = (event, self) => {
    ReactEvent.Synthetic.preventDefault(event);
    onChangeLink(self.ReasonReact.state.uri);
  };

  {
    ...component,

    initialState: () => {uri: ""},

    reducer: (action, _state) => {
      switch (action) {
      | Change(v) => ReasonReact.Update({uri: v})
      };
    },

    render: self => {
      <>
        <p> {ReasonReact.string("URL of your Top Songs playlists")} </p>
        <form onSubmit={self.handle(handleSubmit)}>
          <div>
            <input
              type_="text"
              placeholder="Playlist URL or URI"
              value={self.state.uri}
              onChange={event => {
                let value = ReactEvent.Form.currentTarget(event)##value;
                self.send(Change(value));
              }}
            />
          </div>
          <div>
            <button action="submit">
              {ReasonReact.string("Continue")}
            </button>
          </div>
        </form>
      </>;
    },
  };
};
