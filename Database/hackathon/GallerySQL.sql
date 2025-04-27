Create table Artist(
	aname		char(20) not null,
	birth_place	char(20),
	age			integer,
	astyle	char(20),
	primary key	(aname)
);

Create table Artworks(
	aname	char(20) not null,
	title	char(20),
	price	integer,
	year	integer,
	type	char(20),
	primary key (title),
	foreign key (aname) references Artist(aname)
);

Create table Customer(
	cname	char(20) not null,
	address	char(20),
	amount  integer,
	primary key (cname)	
);

Create table ArtGroups(
	kinds_of_Artworks	char(20),
	primary key (kinds_of_Artworks)
);

Create table A_like(
	aname 	char(20),
	cname 	char(20),
	primary key (aname, cname),
	foreign key (aname) references Artist(aname),
	foreign key (cname) references Customer(cname)
);

Create table G_like(
	kinds_of_Artworks	char(20),
	cname	char(20),
	foreign key (kinds_of_Artworks) references ArtGroups(kinds_of_Artworks),
	foreign key (cname) references Customer(cname)	
);

Create table Purchase(
	title	char(20),
	cname	char(20),
	foreign key (title) references Artworks(title),
	foreign key (cname) references Customer(cname)
);

Create table Classify(
	kinds_of_Artworks	char(20),
	title	char(20),
	primary key (kinds_of_Artworks, title),
	foreign key (kinds_of_Artworks) references ArtGroups(kinds_of_Artworks),
	foreign key (title) references Artworks(title)	
);


SELECT aname, COUNT(*) as prefer
FROM A_like
GROUP BY prefer

