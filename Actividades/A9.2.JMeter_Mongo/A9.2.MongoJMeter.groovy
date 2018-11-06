import com.mongodb.*;

MongoClient cli = new MongoClient("localhost", 27017);
DB mydb = cli.getDB("test");

DBCollection nombres = mydb.getCollection("nombres");

// Insertar un objeto
BasicDBObject bdbo = new BasicDBObject();
bdbo.append("nombre", "Julio");

WriteResult writer = nombres.insert(bdbo, WriteConcern.ACKNOWLEDGED);

if(writer.wasAcknowledged()){
    OUT.println("Se escribio el objeto en la BD");
} else {
    OUT.println("NO se escribio el objeto en la BD");
}

SampleResult.setResponseData(writer.toString().getBytes());

// Insertar un arreglo
bdbo = new BasicDBObject();
BasicDBList bdbl = new BasicDBList();
bdbl.add("55247344");
bdbl.add("55343423");
bdbl.add("53432333");
bdbo.append("telefonos", bdbl);
writer = nombres.insert(bdbo, WriteConcern.ACKNOWLEDGED);
SampleResult.setResponseData(writer.toString().getBytes());

BasicDBObject busqueda = new BasicDBObject("nombre", "Julio");
DBCursor dbo = nombres.find(busqueda);

StringBuilder s = new StringBuilder();
while(dbo.hasNext()){
    DBObject res = dbo.next();    
    s.append(res.toString());
}

vars.put("resultado", s.toString());
