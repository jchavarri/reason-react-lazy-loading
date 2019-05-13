
[@bs.val] external import: string => Js.Promise.t('a) = "";

[@bs.module "react"]
external lazy_: (unit => Js.Promise.t('a)) => 'a = "lazy";
