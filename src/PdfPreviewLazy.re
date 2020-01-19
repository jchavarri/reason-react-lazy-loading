module type T = (module type of PdfPreview);

/*
  Needed for BuckleScript to not import the original component:
  See https://github.com/BuckleScript/bucklescript/issues/3543
 */
[@bs.val] external unsafePlaceholder: (module T) = "undefined";

/* By leveraging the shallow `unsafePlaceholder` definition above,
   we can use PdfPreview types without requiring the PdfPreview.bs.js file */
module UnsafePlaceholder = (val unsafePlaceholder);

/* Because makeProps is defined as external, it doesn't lead to `require`
   statements as BuckleScript is able to inline it in the generated code.
   Note this won't work for other exported functions or values though! */
let makeProps = UnsafePlaceholder.makeProps;
let make =
  LazyImport.(
    lazy_(() => importComponent(UnsafePlaceholder.make, "./PdfPreview.bs"))
  );
