open Routes;

/* State of our component */
type state = {books: Database.books};

/* Actions that can be send to our reducer function */
type action =
  | UpdateBook(Database.book)
  | DeleteBook(int)
  | AddBook(string);

/* This is the way we declare a component */
let component = ReasonReact.reducerComponent("App");

/*
   1. Fix bug:
   'make' is the function a JSX element will call.
   e.g.: this make function will be called with <App/>
 */
let make = (~route, _children) => {
  ...component,
  initialState: () => {books: Database.books},
  /*
     TODO: reducer takes action and state as args
     pattern match on actions and return the new state
   */
  reducer: (action, state) =>
    switch action {
    | UpdateBook(updatedBook) => ReasonReact.Update({
        books: List.map((book: Database.book) => book.id == updatedBook.id ? updatedBook : book, state.books)})
    | DeleteBook(bookId) => ReasonReact.Update({
        books: List.filter((book: Database.book) => book.id != bookId, state.books)})
    | AddBook(title) => ReasonReact.Update({
      books: List.append([{
        id: 100,
        title: title,
        description: "New book",
        category: "New category"
      }: Database.book], state.books)
  })
},
  render: ({state: {books}, reduce}) => {
    /* TODO: write functions that our components needs (future) */
    let page =
      switch route {
      | DashBoardRoute => <DashBoard books />
      | BookDetailsRoute(bookId) => <BookDetail books bookId save=((book) => reduce(() => UpdateBook(book))()) />
      | ManageBooksRoute => <ManageBooks books 
          deleteBook=((bookId) => reduce(() => DeleteBook(bookId))()) 
          addBook=((title) => reduce(() => AddBook(title))()) />
      /* TODO: pattern match with all routes the app has  */
      };
    <div>
      <Navbar books />
      page 
    </div>
      /* TODO: display the Navbar component */
  }
};
