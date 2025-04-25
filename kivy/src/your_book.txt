from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.scrollview import ScrollView
from kivy.lang import Builder
 
# 使用Kivy语言定义界面
kv = '''
BoxLayout:
    orientation: 'vertical'
    Label:
        text: '电子书阅读器'
        size_hint_y: None
        height: 50
    ScrollView:
        do_scroll_x: False
        Label:
            size_hint_y: None
            height: self.texture_size[1]
            text: root.book_content
'''
 
class BookReaderApp(App):
    def build(self):
        self.book_content = open('your_book.txt').read()  # 加载电子书内容，确保文件路径正确
        return Builder.load_string(kv)
 
if __name__ == '__main__':
    BookReaderApp().run()

