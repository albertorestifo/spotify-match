type css = {. "container": string};

[@bs.module] external css: css = "./LayoutView.css";

let component = ReasonReact.statelessComponent("LayoutView");

let make = children => {
  ...component,

  render: _self => {
    <div
      className={
        css##container;
      }> ...children </div>;
  },
};
