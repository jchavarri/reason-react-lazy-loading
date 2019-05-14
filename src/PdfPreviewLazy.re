module type T = (module type of PdfPreview);
/*
  Needed for BuckleScript to not import the original component:
  See https://github.com/BuckleScript/bucklescript/issues/3543
 */
[@bs.val] external component: (module T) = "undefined";

module Lazy: T = {
  include (val component);
  let default = Obj.magic;
  let make = LazyImport.(lazy_(() => import("./PdfPreview.bs")));
};
