module StyleSheet = {
  type t;
  [@bs.module "@react-pdf/renderer"] external make: t = "StyleSheet";
  [@bs.send] external create: (t, Js.t('a)) => Js.t('a) = "";
};

module PDFViewer = {
  [@bs.module "@react-pdf/renderer"] [@react.component]
  external make:
    (~children: React.element, ~className: string, ~style: Js.t('a)) =>
    React.element =
    "PDFViewer";
};

module Document = {
  [@bs.module "@react-pdf/renderer"] [@react.component]
  external make: (~children: React.element) => React.element = "Document";
};

module Page = {
  [@bs.module "@react-pdf/renderer"] [@react.component]
  external make:
    (~children: React.element, ~size: string, ~style: Js.t('a)) =>
    React.element =
    "Page";
};

module View = {
  [@bs.module "@react-pdf/renderer"] [@react.component]
  external make: (~children: React.element, ~style: Js.t('a)) => React.element =
    "View";
};

module Text = {
  [@bs.module "@react-pdf/renderer"] [@react.component]
  external make:
    (~children: React.element, ~style: Js.t('a)=?) => React.element =
    "Text";
};
