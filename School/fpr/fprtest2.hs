data Element =
    Button1 {name1 :: String, text1 :: String}
    |Text {text1 :: String}
    |Panel [Element] deriving (Show)

priklad :: Element
priklad = Panel [
    Button1 "Tlacitko" "text",
    Text "Text"]

data Component = 
    TextBox {name :: String, text :: String}
    | Button {name :: String, value :: String}
    | Container {name :: String, children :: [Component]} deriving (Show)

gui :: Component
gui = Container "My App" [
    Container "Menu" [
        Button "btn_new" "New",
        Button "btn_open" "Open",
        Button "btn_close" "close"],
    Container "Body" [TextBox "textbox_1" "Some text goes here"],
    Container "Footer" []]

listAllButtons::Component->[Component]
listAllButtons (TextBox _ _) = []
listAllButtons (Button name value) = [Button name value]
listAllButtons (Container _ children) = concatMap listAllButtons children





