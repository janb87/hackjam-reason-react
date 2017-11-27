let component = ReasonReact.statelessComponent("App");

let book = (book: Database.book) => {
  let href = "#/detail/" ++ string_of_int(book.id); /*  4. Feature : TODO: should point to correct url with book id */
  <div className="column is-one-quarter" key=(string_of_int(book.id))>
    <div className="card">
      <a href>
        <div className="card-header">
          <p
            className="card-header-title has-text-centered">
            (Utils.ste(book.title))
          </p>
        </div>
        <div className="card-content">
          <div className="content">
            (Utils.ste(book.description))
             <br /> </div>
        </div>
        <div className="card-footer">
          <p
            className="card-footer-item">
            (Utils.ste(book.category))
          </p>
        </div>
      </a>
    </div>
  </div>
};

let make = (~books, _children) => {
  ...component,
  render: (_) =>
    <section className="section">
      <div className="container">
        <div className="columns is-multiline">
          (
            List.map(book, books)
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
        </div>
        /* 4. Feature : TODO display all books */
      </div>
    </section>
};
