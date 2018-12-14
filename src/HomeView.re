type css = {. "title": string};
[@bs.module] external css: css = "./HomeView.css";

let component = ReasonReact.statelessComponent("HomeView");
let make = _children => {
  ...component,

  render: _self =>
    <>
      <h1 className={css##title}>
        {ReasonReact.string("TopMatch for Spotify")}
      </h1>
    </>,
};
