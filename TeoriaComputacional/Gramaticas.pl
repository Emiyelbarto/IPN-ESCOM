% Gramatica Palindromo

p-->[].
p-->[0].
p-->[1].
p-->[0],p,[0].
p-->[1],p,[1].


% Expresiones Aritmeticas

e-->t.
e-->t,[+],e.
e-->t,[-],e.
t-->f.
t-->f,[*],t.
t-->f,[/],t.
f-->[0].
f-->[1].
f-->[2].
f-->[3].
f-->[4].
f-->[5].
f-->[6].
f-->[7].
f-->[8].
f-->[9].
f-->['('],e,[')'].

% Identificadores en C


letra-->[a].
letra-->[b].
letra-->[c].
letra-->[d].
letra-->[e].
letra-->[f].
letra-->['_'].

digito-->[0].
digito-->[1].
digito-->[2].
digito-->[3].
digito-->[4].
digito-->[5].
digito-->[6].
digito-->[7].
digito-->[8].
digito-->[9].

id-->letra.
id-->letra,resto.

resto-->digito.
resto-->letra.

resto-->digito,resto.
resto-->letra,resto.








