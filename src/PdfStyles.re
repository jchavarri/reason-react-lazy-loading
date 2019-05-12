let styles =
  Bindings.StyleSheet.(
    make->create({
      "viewer": {
        "padding": 0,
      },

      "page": {
        "margin": 0,
        "flexDirection": "row",
        "backgroundColor": "#ffffff",
      },
      "title": {
        "fontSize": 30,
        "marginBottom": 30,
      },
      "section": {
        "margin": 10,
        "padding": 10,
        "flexGrow": 1,
      },
    })
  );
