type css = {
  .
  "title": string,
  "subtitle": string,
  "cta": string,
};
[@bs.module] external css: css = "./HomeView.css";

let component = ReasonReact.statelessComponent("HomeView");
let make = _children => {
  let onClick = _event => ReasonReact.Router.push("/you");
  {
    ...component,
    render: _self => {
      <>
        <h1 className={css##title}>
          {ReasonReact.string("Compare your Spotify Top Songs")}
        </h1>
        <p className={css##subtitle}>
          {ReasonReact.string(
             {|See how your music taste compares with your friends by comparing
           the Top Songs playlists.|},
           )}
        </p>
        <button className={css##cta} onClick>
          {ReasonReact.string("Get started")}
        </button>
      </>;
    },
  };
};
