# reason-react-lazy-loading

Example project to show how to use components lazy loading in ReasonReact.

Reason / BuckleScript adaptation from https://medium.freecodecamp.org/how-to-use-react-lazy-and-suspense-for-components-lazy-loading-8d420ecac58.

## How to create a lazy ReasonReact component

If you have a component `Foo` and you want to load it lazily using dynamic `import` and React `lazy`:

1. Copy `LazyImport.re` inside your project. This is just needed once, as it is generic and can be used for all cases.
2. In `Foo.re`, add `let default = make;`
3. Create a new file `FooLazy.re` and include:

    ```reason
    let makeProps = Foo.makeProps;
    let make = LazyImport.(lazy_(() => import("./Foo.bs")));
    ```

That's it!

In this repo, the approach above has been used with `PdfPreview.re` component through `PdfPreviewLazy.re`.

> But... `LazyImport.lazy_` is not type safe! The `make` function in `FooLazy` will not be safe either.

True! But it doesn't need to be, as long as `makeProps` is safe, due to the way [JSX 3](https://reasonml.github.io/reason-react/docs/en/jsx) works in ReasonReact.

## Run Project

```sh
yarn install
yarn start
# in another tab
yarn run webpack
```

After you see the webpack compilation succeed (the `yarn run webpack` step), open up `build/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Run Project with Server

To run with the webpack development server run `yarn run server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

Note that any hot reload on a route will fall back to the root (`/`), so `ReasonReact.Router.dangerouslyGetInitialUrl` will likely be needed alongside the `ReasonReact.Router.watchUrl` logic to handle routing correctly on hot reload refreshes or simply opening the app at a URL that is not the root.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 yarn run server`).

## Build for Production

```sh
yarn run clean
yarn run build
yarn run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).

If you make use of routing (via `ReasonReact.Router` or similar logic) ensure that server-side routing handles your routes or that 404's are directed back to `index.html` (which is how the dev server is set up).

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.