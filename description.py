'''
Describes arcitecture of project. Later I will switch to Doxygen.
'''

from graphviz import Digraph

dot = Digraph(comment='Architecture')

dot.node('Application', 'Application')
dot.node('SubscrManager', 'SubscrManager')
dot.node('Event', 'Event')
dot.node('engineInterface', 'engineInterface')
dot.node('engineSFML', 'engineSFML')
dot.node('Window', 'Window')
dot.node('Instrument', 'Instrument')
dot.node('Component', 'Component')

dot.edge('Application', 'SubscrManager')
dot.edge('Application', 'Window')
dot.edge('Application', 'engineInterface')

dot.edge('SubscrManager', 'Window')
dot.edge('SubscrManager', 'Event')

dot.edge('engineInterface', 'Event')
dot.edge('engineInterface', 'Window')
dot.edge('engineInterface', 'SubscrManager')

dot.edge('engineSFML', 'engineInterface')

dot.edge('Window', 'Event')
dot.edge('Window', 'Component')

dot.node('Instrument', 'Window')

dot.render('architecture', view=True)