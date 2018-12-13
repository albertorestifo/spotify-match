let component = ReasonReact.statelessComponent("Header");

let make = (~title, _children) => {
  ...component,
  render: _self =>
    <div className="header">
      <div className="logo"> {ReasonReact.string(title)} </div>
    </div>,
};
