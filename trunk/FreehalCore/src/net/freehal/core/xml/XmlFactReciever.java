package net.freehal.core.xml;

import java.io.File;

import net.freehal.core.database.DatabaseImpl;

public interface XmlFactReciever {

	public void useXmlFact(DatabaseImpl d, XmlFact xfact, int countFacts,
			long start, File filename, int countFactsSoFar);

}