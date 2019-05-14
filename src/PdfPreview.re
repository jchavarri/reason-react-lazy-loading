open BsPdfViewer;

// Create Document Component
[@react.component]
let make = (~title) =>
  <PDFViewer className="viewer" style=PdfStyles.styles##viewer>
    <Document>
      <Page size="A4" style={PdfStyles.styles##page}>
        <View style={PdfStyles.styles##section}>
          <Text style={PdfStyles.styles##title}> title->React.string </Text>
          <Text>
            "This is a text in a generated PDF file."->React.string
          </Text>
        </View>
      </Page>
    </Document>
  </PDFViewer>;
