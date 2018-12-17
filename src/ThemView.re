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
          | _ => ((-1), "")
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
             List.rev_map(
               ((id, uri)) =>
                 <div key={string_of_int(id)}>
                   <input
                     type_="text"
                     value=uri
                     onChange={event => {
                       let value =
                         ReactEvent.Form.currentTarget(event)##value;
                       self.send(Change((id, value)));
                     }}
                   />
                   <button onClick={_event => self.send(Remove(id))}>
                     {ReasonReact.string("X")}
                   </button>
                 </div>,
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
