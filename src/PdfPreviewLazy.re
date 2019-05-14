module type T = (module type of PdfPreview);
/*
  Needed for BuckleScript to not import the original component:
  See https://github.com/BuckleScript/bucklescript/issues/3543
 */
[@bs.val] external component: (module T) = "undefined";
/* Needed until BuckleScript's module shape is unified */
[@bs.val] [@bs.scope "Object"] external values: 'a => 'b = "values";

module Lazy: T = {
  include (val component);
  let make =
    LazyImport.(
      lazy_(() =>
        import("./PdfPreview.bs")
        |> Js.Promise.then_((res: (module T)) => {
             module Res = (val res->Obj.magic##default->values->Obj.magic: T);
             Js.Promise.resolve({"default": Res.make}->Obj.magic);
           })
      )
    );
};
