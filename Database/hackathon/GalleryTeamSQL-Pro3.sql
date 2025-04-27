select a.title, a.price
from artwork a
where a.title in (select c.title
                    from classify c
					group by c.title
					having count(c.kinds_of_arts) >= 2)
and a.price = (select max(a2.price)
                 from artwork a2
				 where a2.title in (select c2.title
				                      from classify c2
			   					     group by c2.title
									 having count(c2.kinds_of_arts) >= 2
								   )
              )
