#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_

#include <RtypesCore.h>
#include <TObject.h>

class Database : public TObject {
public:
	Double_t myNumber;

	ClassDef(Database, 1)
};

#endif /* SRC_DATABASE_H_ */
