from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout

class IndexPage(BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.join = Button(text = 'Hello World')
        self.add_widget(self.join)

class TestApp(App):
    def build(self):
        return IndexPage()

if __name__ == '__main__':
    app = TestApp()
    app.run()
    