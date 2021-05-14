
# Unicode is meant to handle text
# In Python3, Literal strings are unicode by default
# Unicode takes more size

# Using unicode as var
#Δx = 1
#print(Δx)

example = 'raw vegan chocolate cocoa pie w chocolate &amp; vanilla cream\\uD83D\\uDE0D\\uD83D\\uDE0D\\u2764\\uFE0F Present Moment Caf\\u00E8 in St.Augustine\\u2764\\uFE0F\\u2764\\uFE0F '

uexample = u'raw vegan chocolate cocoa pie w chocolate &amp; vanilla cream\\uD83D\\uDE0D\\uD83D\\uDE0D\\u2764\\uFE0F Present Moment Caf\\u00E8 in St.Augustine\\u2764\\uFE0F\\u2764\\uFE0F '

print(example)
print(uexample)


#import codecs
#new_str = codecs.unicode_escape_decode(example)
#print(new_str)
#new_new_str = new_str.encode('utf-16', 'surrogatepass').decode('utf-16')
#print(new_new_str)
