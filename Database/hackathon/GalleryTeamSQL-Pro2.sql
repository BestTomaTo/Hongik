select a.aname, avg(w.price) as maxpri
from artists a, artwork w
where a.aname = w.aname
group by a.aname
having avg(w.price) = (select min(avgpri)
                         from (select avg(price) as avgpri
						         from artwork w2
							    group by w2.aname
							   )
					  )

					  