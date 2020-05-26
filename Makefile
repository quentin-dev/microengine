BUILDDIR = build

RM += -r

release:
	cmake -S . -B $(BUILDDIR) -DCMAKE_BUILD_TYPE=Release
	cmake --build $(BUILDDIR) -j8

debug:
	cmake -S . -B $(BUILDDIR) -DCMAKE_BUILD_TYPE=Debug
	cmake --build $(BUILDDIR) -j8

.PHONY: doc
doc:
	cmake -S . -B $(BUILDDIR)
	cmake --build $(BUILDDIR) --target doxygen -j8

clean:
	cmake --build $(BUILDDIR) --target clean

clean-all:
	$(RM) $(BUILDDIR)