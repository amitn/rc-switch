

CXXFLAGS=-DRPI -g3

fan-ctl: RCSwitch.o fan-ctl.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o fan-ctl
