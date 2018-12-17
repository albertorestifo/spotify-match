type state = {uris: list((int, string))};
type action =
  | Add
  | Change((int, string))
  | Remove(int);

let component = ReasonReact.reducerComponent("ThemView");
let make = _children => {
  {
    ...component,
    initialState: () => {uris: []},

    reducer: (action, {uris}) => {
      switch (action) {
      | Add =>
        /* Lits are populated in reverse order, so the first element is the
           last one added */
        let (lastID, _) =
          try (List.nth(uris, 0)) {
          | Failure("nth") => ((-1), "")
          };

        ReasonReact.Update({uris: [(lastID + 1, ""), ...uris]});
      | Remove(n) =>
        ReasonReact.Update({uris: List.filter(((i, _)) => i !== n, uris)})
      | Change((n, v)) =>
        let nextUris =
          List.map(
            ((i, prevVal)) => i === n ? (i, v) : (i, prevVal),
            uris,
          );
        ReasonReact.Update({uris: nextUris});
      };
    },

    render: self => {
      <>
        {ReasonReact.array(
           Array.of_list(
             List.map(
               ((n, uri)) =>
                 <input
                   key={string_of_int(n)}
                   type_="text"
                   value=uri
                   onChange={event => {
                     let value = ReactEvent.Form.currentTarget(event)##value;
                     self.send(Change((n, value)));
                   }}
                 />,
               self.state.uris,
             ),
           ),
         )}
        <button onClick={_event => self.send(Add)}>
          {ReasonReact.string("Add one")}
        </button>
      </>;
    },
  };
};
