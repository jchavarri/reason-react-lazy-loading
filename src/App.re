type action =
  | Clicked
  | InputChanged(string);

type state = {
  name: string,
  showPDFPreview: bool,
};

let reducer = (state, action) =>
  switch (action) {
  | Clicked => {...state, showPDFPreview: true}
  | InputChanged(value) => {...state, name: value}
  };

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(reducer, {name: "", showPDFPreview: false});

  let greeting = "Hello " ++ state.name;

  <div className="App">
    <input
      placeholder="Enter your name"
      type_="text"
      onChange={e =>
        dispatch(InputChanged(e->ReactEvent.Form.target##value))
      }
    />
    <button onClick={_ => dispatch(Clicked)}>
      "Generate PDF"->React.string
    </button>
    {state.showPDFPreview
       ? <React.Suspense fallback={<div> "Loading..."->React.string </div>}>
           <PdfPreviewLazy.Lazy title=greeting />
         </React.Suspense>
       : React.null}
  </div>;
};
