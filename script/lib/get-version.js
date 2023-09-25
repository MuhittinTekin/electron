const { spawnSync } = require('node:child_process');
const path = require('node:path');

const { ELECTRON_DIR, getBuildtoolsExecutable, getOutDir } = require('./utils');

// Print the value of electron_version gn arg.
module.exports.getElectronVersion = () => {
  // Execute "gn args" to receive arg info.
  const gn = getBuildtoolsExecutable('gn');
  const outDir = path.resolve(ELECTRON_DIR, '..', 'out', getOutDir());
  const output = spawnSync(gn, ['args', outDir, '--list=electron_version', '--short', '--json']);
  if (output.status !== 0) {
    throw new Error(`Failed to get electron_version arg: ${output.stdout}`);
  }
  // Parse the arg value.
  const version = JSON.parse(output.stdout)[0];
  if (version.current) { return version.current.value; } else { return version.default.value; }
};
