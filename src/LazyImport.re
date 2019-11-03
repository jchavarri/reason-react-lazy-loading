
[@bs.val] external import: string => 'a = "import";

[@bs.module "react"]
external lazy_: (unit => Js.Promise.t('a)) => 'a = "lazy";
